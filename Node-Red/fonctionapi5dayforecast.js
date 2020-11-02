r=0;
rt=0;

for (i=0; i<40; i++){
    if (msg.payload[i].rain){
        r+=1;
        rt+=msg.payload[i].rain['3h']
    }
}
msg.rain=r;
msg.total=rt;
t=0;
for (i=0; i<40; i++){
    if(parseInt(msg.payload[i].main.temp) <= 0){
        t+=1;
    }
}
msg.temp=t;
return msg;
