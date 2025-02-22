#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Dec 31 14:09:06 2022

@author: vistan-devserver
"""


import os
import json
import time


def ClearLogs(path):
    file_name = path+'params.json'
    with open(file_name) as f:
        params = json.loads(f.read())
    if (time.time()-params['log_file_created_time'])>=params['clear_log_time']:
        os.system("rm "+path +"Navi.log")
        from LogGenerator import logging
        params['log_file_created_time']=time.time()
        params=json.dumps(params)
        with open(file_name, 'w') as outfile:
            outfile.write(params)
            logging.info("Logs are cleared")
    else:
        from LogGenerator import logging
        logging.info("Logs are not cleared")
        
if __name__=="__main__":
    pass