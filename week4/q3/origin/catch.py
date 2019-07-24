import requests
import csv
import random
import time
import socket
import http.client
# import urllib.request
from bs4 import BeautifulSoup 


def get_content(url , data = None):
    header={
        'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
        'Accept-Encoding': 'gzip, deflate, sdch',
        'Accept-Language': 'zh-CN,zh;q=0.8',
        'Connection': 'keep-alive',
        'User-Agent': 'Mozilla/5.0 (Windows NT 6.3; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.235'
    }
    timeout = random.choice(range(80, 180))
    while True:
        try:
            rep = requests.get(url,headers = header,timeout = timeout)
            rep.encoding = 'utf-8'
            # req = urllib.request.Request(url, data, header)
            # response = urllib.request.urlopen(req, timeout=timeout)
            # html1 = response.read().decode('UTF-8', errors='ignore')
            # response.close()
            break
        # except urllib.request.HTTPError as e:
        #         print( '1:', e)
        #         time.sleep(random.choice(range(5, 10)))
        #
        # except urllib.request.URLError as e:
        #     print( '2:', e)
        #     time.sleep(random.choice(range(5, 10)))
        except socket.timeout as e:
            print( '3:', e)
            time.sleep(random.choice(range(8,15)))

        except socket.error as e:
            print( '4:', e)
            time.sleep(random.choice(range(20, 60)))

        except http.client.BadStatusLine as e:
            print( '5:', e)
            time.sleep(random.choice(range(30, 80)))

        except http.client.IncompleteRead as e:
            print( '6:', e)
            time.sleep(random.choice(range(5, 15)))

    return rep.text
    # return html_text

def get_data(html_text):
    final = []
    bs = BeautifulSoup(html_text, "html.parser")  # 创建BeautifulSoup对象
    body = bs.body # 获取body部分
    datas = body.find_all('div', {'class': 'file input-view'})  # 找到id为7d的div

    inputs = []
    for data in datas:
        data = data.find('pre')
        inputs.append(data.string)

    return inputs

def get_data_out(html_text):
    final = []
    bs = BeautifulSoup(html_text, "html.parser")  # 创建BeautifulSoup对象
    body = bs.body # 获取body部分
    datas = body.find_all('div', {'class': 'file output-view'})  # 找到id为7d的div

    outputs = []
    for data in datas:
        data = data.find('pre')
        outputs.append(data.string)

    return outputs


from os import path, listdir, makedirs, remove

if path.isdir('./data'):
    fs = listdir('./data')
    for f in fs:
        # print(f)
        remove('./data/'+ f)
else:
    makedirs('data')

if path.isdir('./err'):
    fs = listdir('./err')
    for f in fs:
        # print(f)
        remove('./err/'+ f)
else:
    makedirs('err')

import re
# from os import path, listdir, makedirs, remove
def write_data(datas, s):
    cnt = 0
    for data in datas:
        cnt += 1
        p = './data/data-'
        if re.findall(r'.*\.\.\..*', data):
            p = './err/data-'
            # print(cnt)
        
        with open(p  + str(cnt) + s, 'w') as f:
            f.write(data)


import os
if __name__ == '__main__':
    url ='http://codeforces.com/contest/571/submission/12873480'
    # url ='http://www.weather.com.cn/weather/101190401.shtml'

    html = ''
    if not os.path.exists('source.html'):
        html = get_content(url)
        with open('source.html', 'w') as f:
            f.write(html)
    else:
        with open('source.html', 'r') as f:
            html = f.read()

    result = get_data(html)
    # print(result)
    write_data(result, '.in')

    result = get_data_out(html)
    # print(result)
    write_data(result, '.out')