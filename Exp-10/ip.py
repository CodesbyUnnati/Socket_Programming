import os
import getmac
ip = ""
while ip != "exit":
   ip = input("\nEnter IP address [or exit]: ")
   if ip == "exit":
       continue
   os.system("ping {}".format(ip))
   msg = input("\nRetrieve MAC address? [y/n]: ")
   if msg == "n":
       continue
   mac = getmac.get_mac_address(ip = ip)
   print("MAC address: {}".format(mac))
print("\nExiting")

//run it in VS Code and write ur IP
