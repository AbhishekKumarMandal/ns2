BEGIN {
 tcpsend=0;
 tcpreceive=0;
 udpsend=0;
 udpreceive=0;
}

{
 event=$1;
 type=$5;
 if(event=="+")
 {
   if(type=="tcp")
    tcpsend++;
   if(type=="cbr")
    udpsend++;
 }
 
 if(event=="r")
 {
  if(type=="tcp")
   tcpreceive++;
  if(type=="cbr")
   udpreceive++;
 }

}

END {
 printf("\ntcp send: %d  tcp receive: %d\n",tcpsend,tcpreceive);
 printf("udp send: %d udp receive: %d\n",udpsend,udpreceive);
}

