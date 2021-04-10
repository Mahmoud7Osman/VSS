from pibyone import loader
from random import randint
import time

NRM="\x1B[0m"
RED="\x1B[91m"
GRN="\x1B[92m"
YEL="\x1B[93m"
BLU="\x1B[94m"
MAG= "\x1B[95m"
CYN= "\x1B[96m"
WHT= "\x1B[97m"

name="""
$RED __     __    _      V7X              _____
$GRN \ \   / /_ _(_)_ __ ___  _   _ ___  |___  |_  __ $NRM  V7X
$YEL  \ \ / / _` | | '__/ _ \| | | / __|    / /\ \/ / $NRM   Super Sploit
$BLU   \ V / (_| | | | | (_) | |_| \__ \   / /  >  <  $NRM Vss
$CYN    \_/ \__,_|_|_|  \___/ \__,_|___/  /_/  /_/\_\ $NRM   Welcome


"""

name=name.replace("$RED",RED)
name=name.replace("$GRN",GRN)
name=name.replace("$YEL",YEL)
name=name.replace("$BLU",BLU)
name=name.replace("$CYN",CYN)
name=name.replace("$NRM",NRM)

def load(text, rep):
    tlen=len(text)
    for char in range(0,len(text)-1):
     print (text[char],end='',flush=True)
     time.sleep(0.001)
    loader.eq_load("Loading the VSS",randint(2,6))


load(name,1)
