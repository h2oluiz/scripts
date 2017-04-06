# Enviando 

#!/bin/sh
HOST="000.000.000.00"
USER="ftp-luiz"
PASSWD="jkjkjllj"
FILE=`ls xerf704*`

ftp -n $HOST <<END_SCRIPT
quote USER $USER
quote PASS $PASSWD
cd remessa
put $FILE 
quit
END_SCRIPT
exit 0


# Recebendo 

#!/bin/sh

HOST="000.000.000.00"
USER="ftp-luiz"
PASSWD="jkjkjllj"

ftp -n $HOST <<END_SCRIPT
quote USER $USER
quote PASS $PASSWD
cd retorno
mget MCALC_TESTE*
quit
END_SCRIPT
exit 0
