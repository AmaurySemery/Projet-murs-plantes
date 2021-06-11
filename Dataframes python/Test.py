import pandas as pd
import numpy as np
import json

a=1

dGW = pd.DataFrame([('parrot',   a, 'second'),
                    ('lion',     80.5, 1),
                    ('monkey', np.nan, None)],
                  columns=('name', 'max_speed', 'rank'))

df = pd.DataFrame({'age':    [a],
                   'height': [a],
                   'weight': [a]})