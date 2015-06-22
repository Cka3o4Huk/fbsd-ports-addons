--- lib/misc/text.c.orig	2015-06-22 10:12:49 UTC
+++ lib/misc/text.c
@@ -260,6 +260,27 @@ void del_final_numeric_char(char *word)
 	word[len - offset] = NULLSYM;
 }
 
+int dist(int i, int j, int ls, int lt,int d[ls+1][lt+1], const char *s, const char *t) {
+	if (d[i][j] >= 0) return d[i][j];
+
+	int x;
+	if (i == ls)
+		x = lt - j;
+	else if (j == lt)
+		x = ls - i;
+	else if (s[i] == t[j])
+		x = dist(i + 1, j + 1,d, ls, lt, s, t);
+	else {
+		x = dist(i + 1, j + 1,d, ls, lt, s, t);
+
+		int y;
+		if ((y = dist(i, j + 1,d, ls, lt, s, t)) < x) x = y;
+		if ((y = dist(i + 1, j,d, ls, lt, s, t)) < x) x = y;
+		x++;
+	}
+	return d[i][j] = x;
+}
+
 int levenshtein(const char *s, const char *t)
 {
 	int ls = strlen(s), lt = strlen(t);
@@ -269,25 +290,6 @@ int levenshtein(const char *s, const cha
 		for (int j = 0; j <= lt; j++)
 			d[i][j] = -1;
  
-	int dist(int i, int j) {
-		if (d[i][j] >= 0) return d[i][j];
- 
-		int x;
-		if (i == ls)
-			x = lt - j;
-		else if (j == lt)
-			x = ls - i;
-		else if (s[i] == t[j])
-			x = dist(i + 1, j + 1);
-		else {
-			x = dist(i + 1, j + 1);
- 
-			int y;
-			if ((y = dist(i, j + 1)) < x) x = y;
-			if ((y = dist(i + 1, j)) < x) x = y;
-			x++;
-		}
-		return d[i][j] = x;
-	}
-	return dist(0, 0);
+	
+	return dist( 0, 0, d, ls, lt, s, t);
 }
