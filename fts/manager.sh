black='\033[30m'
red='\033[1;91m'
green='\033[1;92m'
yellow='\033[2;93m'
blue='\033[1;94m'
white='\033[1;97m'
printf $green"Starting ZAnaconda File Transfer Session\n"$white
path=$(pwd)
path+=$(printf '/fts/')
trap '\n' SIGINT
gcc $path/session/sender.c -o $path/session/send
gcc $path/session/receiver.c -o $path/session/receiver
ip=$1
port=$2
port=$(($port + 5))
upload(){
printf $yellow"Starting Z-File-Uploader Script... (Type 'stop' to stop)\n"
printf $red"Enter File name (or path) to send\n"$green
xterm -T Uploader -geometry -100+10 -bg blue -e $path/session/send 'none' $ip $port &
}
help(){
echo "Command upload   (upload   <file> <destination>-)"
echo "Command download (download <file> <destination>-)"
echo "Command cd       (cd       <path>---------------)"
echo "Command help     (help--------------------------)"
echo "Command exit     (exit--------------------------)"
echo "Command ls       (ls----------------------------)"
echo "Command pwd      (pwd---------------------------)"
}

download(){
printf $yellow"Starting Z-File-Downloader Script... (Type 'stop' to stop)\n"
printf $red"Tip: Enter File name to Download (Not the path) \n"$green
xterm -T Downloader -geometry -100+500 -bg blue -e $path/session/receiver $ip $port &
}

while [ 1 ];do
printf "$green(CMD)"$red"-"$green"(ZLR)"$red"-> "$white
read vcmd
if [ -f $path/data/$(echo $vcmd | head -n1 | awk '{print $1;}') ];then
  $vcmd
else
  printf $red"(CMD)-(ZLR)"$green"----------[$vcmd Not Found, type help]\n"
fi
done
