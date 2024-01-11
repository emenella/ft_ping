#!/bin/bash

IMAGE_NAME="ft_ping"
SCRIPT_PATH="$( cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"

echo "Path: $SCRIPT_PATH"

if [[ "$(docker images -q $IMAGE_NAME 2> /dev/null)"  == "" ]] ; then
    echo "L'image $IMAGE_NAME n'a pas été trouvée. Vous devriez peut-être la construire."
fi

docker run -it --mount type=bind,source="$SCRIPT_PATH",target=/root/ft_ping $IMAGE_NAME