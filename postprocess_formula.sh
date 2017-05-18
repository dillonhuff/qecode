cat $1 | tr -d '\n' | sed -e 's/\*\*/^/g' | sed -e 's/\. //g'
