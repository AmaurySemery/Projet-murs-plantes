import pandas as pd
import numpy as np
import json
from time import sleep

a=1
sleepmillisecond=0.1
sleepsecond=1
sleep10second=10
sleep30second=30
sleepminut=60
sleephour=3600


df = pd.DataFrame(columns=['EV1','EV2'])
for i in range(a+1):
    i = 1
    b = i + 1
    c = i - 1
    df = df.append({'EV1': b,'EV2' : c}, ignore_index=True)
    print(df)
    sleep(sleepsecond)
