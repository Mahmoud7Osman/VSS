#!/bin/bash

mkdir /opt/vss &> /dev/null
cp anim/VSS_Icon.png /opt/vss  &> /dev/null
(cat dapp/vss.desktop | sed "s|Path=|Path=$PWD|g") > ~/Desktop/vss.desktop
chmod +x ~/Desktop/vss.desktop &> /dev/null

echo "WARNING !!! This Tool's Malwares Need A Professional Linux User To Manage it remotely, Or Malware will be noisy on the Network"
echo "Info      : Nothing is Automated, Every thing is Manual"
if [ "$PREFIX" == '' ];then
    APD='apt'
    PREFIX="/"
else
    APD='pkg'
    echo "Warning: zsession will not work on termux or any envirenment without GUI, but in the next version will be available, (Need GUI Access)"
fi
if [ ! -f "$PREFIX/bin/pip3" ];then
    $APD install python3-pip &> /dev/null
fi
if [ ! -f "$PREFIX/bin/python3" ];then
    $APD install python3 &> /dev/null
fi
echo "|----> [+] Starting Setup.... ($APD) "

chmod +x console/*/*/vcs.*
chmod +x scripts/*

if [ ! -f $PREFIX'/bin/gcc' ];then
   echo "| Installing gcc compiler... (Please be Patient)"
   $APD install clang -y &> /dev/null
fi

if [ ! -f $PREFIX'/bin/nc' ];then
   echo "| Installing ncat...         (Please be Patient)"
   $APD install netcat -y &> /dev/null
fi
if [ ! -f $PREFIX"/bin/xterm" ]; then
   $APD install xterm -y &> /dev/null
fi

if [ ! -f $PREFIX"/bin/morse" ]; then
   echo "| installing seffect (Morse)"
   $APD install morse -y &> /dev/null
fi

if [ ! -f $PREFIX"/bin/python3" ]; then
   echo "| installing Python3 "
   $APD install python -y &> /dev/null
fi

if [ ! -f $PREFIX"/bin/pip3" ]; then
   echo "| installing Pip3 "
   $APD install python3-pip -y &> /dev/null
fi

pip3 install pibyone &> /dev/null
echo "|----> [+] Okay"
g++ alerts/alert.cpp -o alerts/alert &> /dev/null
g++ alerts/why.cpp -o alerts/why     &> /dev/null
alerts/why
alerts/alert

if [ -f .term.vcc ]; then
   echo "Before, You agree to the term of usage attached here:  "
   printf "Continue [Y/n]  "
   read ans
   if [ "$ans" == "Y" ] || [ "$ans" == "y" ]; then
      echo "Done, Good luck with testing"

      rm .term.vcc
      echo "Please Subscribe to Vairous7x on youtube Before starting (:"
      (firefox https://www.youtube.com/c/Vairous7x/videos &) &> /dev/null
      sleep 5
   else
      echo "Aborted"

   fi
fi
