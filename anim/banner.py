from pibyone import banner
from random import randint
from random import randint
import time

te=[
"Exploit The Linux World //////  ///// /// // /",
"Where is the Payload ????",
"Check /etc/system.cfg for system logs :)",
"where is the Zsession handler ???",
"- - - - - - - - - - Are You Hacked ??  - - - - - - - - - - - ",
"Oh shit, Linux is open source ?!?!!!!!",
"Linux Nightmare, soon will be 'Windows&Linux Nightmare'",
"Do you checked if /var/.sys.* Available ???",
"Can you tell me the VCS virus Path ?",
"- - - - - - - - - Vairous 7x Super Sploit - - - - - - - - ",
"Where am i now ?? Do you checked if ./.system.cfg exist ???",
"Are you hacked by VSS ??? Look at clean command",
"Try Help !!!!!!!!!!!!",
"Oh shit, Firewall is playing with vcs virus",
"Can you change the hash ???",
"Do not upload to virus total please, try 'convert' command",
"Email from dany@hotmail.com: Hiii, Can you hack my MAC OS ??",
"Message From Rami: 'My Ubuntu got hacked can you help me...'",
"Message from your girl: 'My MAC OS got hacked after i opened 'photo.sh' in my Computer terminal",
"Alert: Check ./system.cfg ",
"Do You Hacked a MAC OS Now ????",
"Do You Hacked Someone termux ??",
"Are you using this with illegal purposes ??"

]

c=[
"\x1B[0m",
"\x1B[91m",
"\x1B[92m",
"\x1B[93m",
"\x1B[94m",
"\x1B[95m",
"\x1B[96m",
"\x1B[97m"]

l=[
banner.smallskull(),
banner.detailed_skull(),
banner.linux(),
banner.shotgun(),
banner.pistol(),
]

def load(text, rep):
    tlen=len(text)
    print( c[randint(0,len(c)-1)]+l[randint(0,len(l)-1)],  c[randint(0,len(c)-1)],te[randint(0,len(te)-1)])

load(l,1)
