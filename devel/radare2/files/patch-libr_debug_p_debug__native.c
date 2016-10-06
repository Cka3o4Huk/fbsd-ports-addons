--- libr/debug/p/debug_native.c.orig	2016-10-03 12:33:47 UTC
+++ libr/debug/p/debug_native.c
@@ -804,7 +804,7 @@ static RList *r_debug_native_sysctl_map 
 	if (sysctl (mib, 4, NULL, &len, NULL, 0) != 0) return NULL;
 	len = len * 4 / 3;
 	buf = malloc(len);
-	if (!buf) {return NULL};
+	if (!buf) {return NULL;};
 	if (sysctl (mib, 4, buf, &len, NULL, 0) != 0) {
 		free (buf);
 		return NULL;
@@ -1425,7 +1425,7 @@ static RList *r_debug_desc_native_list (
 	if (sysctl (mib, 4, NULL, &len, NULL, 0) != 0) return NULL;
 	len = len * 4 / 3;
 	buf = malloc(len);
-	if (!buf) {return NULL};
+	if (!buf) {return NULL;};
 	if (sysctl (mib, 4, buf, &len, NULL, 0) != 0) {
 		free (buf);
 		return NULL;
