#!/bin/bash
for i in $(ls -R /sigef/site/media | grep -E '^/' | tr -d ':'); do 
  echo "==============================="
  echo caminho: $i
  chown sigef:sigef $i
  sleep 2m
  echo "==============Feito============"
done

