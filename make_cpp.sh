#! /bin/sh

CMD=make
if [ -z $1 ]
then
  :
else
  if [ $1 = clean ]
  then
    CMD="make clean"
  fi
fi
/bin/ls |grep -P '^\d+$' | parallel --no-notice 'cd {}/cpp && '"$CMD"' 2>&1 || pwd'
