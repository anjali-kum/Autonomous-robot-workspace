import requests
import socket
from LogGenerator import logging
import urllib.request
import sys
import json 

class connection:
    def __init__(self,params):
        self.params = params
        self.IP=''
        self.fail_count=0
    def connect(self,host='http://google.com'):
        self.count=0
        try:
            urllib.request.urlopen(host) #Python 3.x
            logging.info("Internet connection successfull")
            self.count=self.count+1
        except:
            logging.error("No Internet Connection")
    def PrivateIP_address(self):
        try:
            s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
            s.connect(('8.8.8.8',80))
            self.Private_ip=s.getsockname()[0]
            logging.info(f"Local IP : {self.Private_ip}")
            self.count=self.count+1
        except:
            #print(e)
            logging.error("Failed fetching private IP")
    def Permissions(self):
        try:
            requests.get('http://'+self.params['cloud_application_ip']+'/api/robodine/latest')
            self.count=self.count+1
        except:
            logging.error("dont have permission to access the site")
            if self.IP!='':
                requests.post('http://'+self.params['Cloud_Permission_Address']+'/api/ip/post',data={'restaurant':self.params['Restuarant_Name'],'ip':self.IP})
                logging.info(f"Permissions were given to IP {self.IP}")
                self.count=self.count+1
    def PublicIP(self):
        try:
            #self.connect(host='http://google.com')
            self.IP=requests.get('https://api.ipify.org').text
            logging.info(f"network public IP :{self.IP}")
            #print('connect1',self.count)
            self.count=self.count+1
        except:
            logging.error("Failed fetching Public IP")
    def run(self):
        self.connect(host='http://google.com')
        self.PrivateIP_address()
        self.PublicIP()
        self.Permissions()
        return self.count
    def StartConnection(self):
        self.count=0
        while self.count!=4:
            self.run()
            logging.info(f"check value :{self.count}")
            self.fail_count+=1
            if self.fail_count>=10:
                logging.error("Breaking the code because of connection failure")
                sys.exit()
        return self.Private_ip
        
if __name__=="__main__":  
    from pathlib import Path
    source_path = Path(__file__).resolve()
    source_dir = source_path.parent
    path=str(source_dir)+'/'
    file_name = path+'params.json'
    with open(file_name) as f:
        params = json.loads(f.read())
    fail_count=0               
    check=0
    connect=connection(params)
    while check!=4:
        #print(check)
        check=connect.run()
        logging.info(f"check value :{check}")
        #print(check)
        fail_count+=1
        if fail_count>=10:
            sys.exit()