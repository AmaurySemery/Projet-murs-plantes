S1 = msg.req.params.s1;
S2 = msg.req.params.s2;
S3 = msg.req.params.s3;
m = (parseInt(S1) + parseInt(S2) + parseInt(S3)) / 3;
msg.moyenne = parseInt(m);
msg.payload = parseInt(m);
return msg;
