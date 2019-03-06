BEGIN {
 send=0;
 received=0;
 drop=0;
}

{
 event=$1;
 type=$5;
 
 if(type=="cbr")
 {
  if(event=="+")
   send++;
  else if(event=="r")
   received++;
  else if(event=="d")
   drop++;
 }

}
END {
 printf("send: %d\n", send);
 printf("received: %d\n", received);
 printf("dropped: %d", drop);
}
