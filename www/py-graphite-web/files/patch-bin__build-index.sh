--- bin/build-index.sh.orig	2015-11-27 18:37:16 UTC
+++ bin/build-index.sh
@@ -1,17 +1,19 @@
-#!/bin/bash
+#!/bin/sh
 
 if [ "$GRAPHITE_ROOT" = "" ]
 then
-  GRAPHITE_ROOT="/opt/graphite"
+  GRAPHITE_ROOT="%%PREFIX%%/graphite"
 fi
 
 if [ "$GRAPHITE_STORAGE_DIR" = "" ]
 then
-  GRAPHITE_STORAGE_DIR="${GRAPHITE_ROOT}/storage"
+  GRAPHITE_STORAGE_DIR="/var/db/graphite"
 fi
 
-
-WHISPER_DIR="${GRAPHITE_STORAGE_DIR}/whisper"
+if [ "$WHISPER_DIR" = "" ]
+then
+  WHISPER_DIR="/var/db/carbon/whisper/"
+fi
 
 if [ ! -d "$WHISPER_DIR" ]
 then
@@ -19,13 +21,17 @@ then
   exit 1
 fi
 
-INDEX_FILE="${GRAPHITE_STORAGE_DIR}/index"
-TMP_INDEX="${GRAPHITE_STORAGE_DIR}/.index.tmp"
+if [ "$INDEX_FILE" = "" ]
+then
+  INDEX_FILE="${GRAPHITE_STORAGE_DIR}/index"
+fi
+
+TMP_INDEX=${INDEX_FILE%%index}.index.tmp
 
 rm -f $TMP_INDEX
 cd $WHISPER_DIR
 touch $INDEX_FILE
 echo "[`date`]  building index..."
-find -L . -name '*.wsp' | perl -pe 's!^[^/]+/(.+)\.wsp$!$1!; s!/!.!g' > $TMP_INDEX
+find -L . -name '*.wsp' | sed -E 's!^[^/]+/(.+)\.wsp$!\1!; s!/!.!g' > $TMP_INDEX
 echo "[`date`]  complete, switching to new index file"
 mv -f $TMP_INDEX $INDEX_FILE
