import requests

url = "http://127.0.0.1:8080/check.php"
PHPSESSID = 'bda0b8493b29dba57ae35581fe7d73f3'

for i in range(1000):
    requests.get(url, cookies={'PHPSESSID': PHPSESSID})

