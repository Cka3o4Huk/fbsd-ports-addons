--- framework/pym/play/commands/modulesrepo.py.orig	2016-09-27 10:16:53 UTC
+++ framework/pym/play/commands/modulesrepo.py
@@ -32,7 +32,7 @@ DEFAULT_REPO = 'https://www.playframewor
 
 def load_module(name):
     base = os.path.normpath(os.path.dirname(os.path.realpath(sys.argv[0])))
-    mod_desc = imp.find_module(name, [os.path.join(base, 'framework/pym')])
+    mod_desc = imp.find_module(name, [os.path.join(base, 'framework/pym')] + sys.path)
     return imp.load_module(name, mod_desc[0], mod_desc[1], mod_desc[2])
 
 json = load_module('simplejson')
