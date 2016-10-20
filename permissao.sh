#!/bin/bash
for i in $(ls -R /home/luiz/Documentos/scripts/sgf-master | grep -E '^/' | tr -d ':'); do 
  echo "==============================="
  echo caminho: $i
  chown sigef:sigef $i/*
  sleep 2m
  echo "==============Feito============"
done

