--- framework/pym/play/cmdloader.py.orig	2016-09-27 10:15:58 UTC
+++ framework/pym/play/cmdloader.py
@@ -1,6 +1,7 @@
 import imp
 import os
 import warnings
+import traceback
 
 def play_formatwarning(msg, *a):
     # ignore everything except the message
@@ -11,7 +12,7 @@ warnings.formatwarning = play_formatwarn
 
 class CommandLoader:
     def __init__(self, play_path):
-        self.path = os.path.join(play_path, 'framework', 'pym', 'play', 'commands')
+        self.path = os.path.join(os.path.dirname(__file__), 'commands')
         self.commands = {}
         self.modules = {}
         self.load_core()
@@ -24,6 +25,7 @@ class CommandLoader:
                     mod = load_python_module(name, self.path)
                     self._load_cmd_from(mod)
                 except:
+                    traceback.print_exc()
                     warnings.warn("!! Warning: could not load core command file " + filename, RuntimeWarning)
 
     def load_play_module(self, modname):
