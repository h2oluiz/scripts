#!/bin/bash
## Bash Script to clear cached memory on (Ubuntu/Debian) Linux
## By Philipp Klaus
## see <http://blog.philippklaus.de/2011/02/clear-cached-memory-on-ubuntu/>
 
if [ "$(whoami)" != "root" ]
then
echo "Você tem que executar este script como root!"
exit 1
fi
 
# Obter Informações da RAM
freemem_before=$(cat /proc/meminfo | grep MemFree | tr -s ' ' | cut -d ' ' -f2) && freemem_before=$(echo "$freemem_before/1024.0" | bc)
cachedmem_before=$(cat /proc/meminfo | grep "^Cached" | tr -s ' ' | cut -d ' ' -f2) && cachedmem_before=$(echo "$cachedmem_before/1024.0" | bc)
 
# Informações de saída
echo -e "Este script irá limpar a memória cache e liberar a sua memória RAM. \n\n No momento em que você tem $cachedmem_before MiB em cache e $freemem_before MiB de memória livre."
 
# Test sync
if [ "$?" != "0" ]
then
echo "Algo deu errado, é impossível para sincronizar o sistema de arquivos."
exit 1
fi

#Parando o SIGEF 

supervisorctl stop sigef
 
# Limpar Filesystem usando o "sync" e Limpar Caches
sync && echo 3 > /proc/sys/vm/drop_caches
 
freemem_after=$(cat /proc/meminfo | grep MemFree | tr -s ' ' | cut -d ' ' -f2) && freemem_after=$(echo "$freemem_after/1024.0" | bc)
 
# Output Summary
echo -e "Esta liberando $(echo "$freemem_after - $freemem_before" | bc) MB, então agora você tem $freemem_after MB de RAM livre."
 
exit 0 

#inciando o sigef 

#supervisorctl start sigef


