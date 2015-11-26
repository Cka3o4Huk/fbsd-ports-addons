--- libgitg/gitg-lanes.vala.orig	2014-12-24 08:35:18 UTC
+++ libgitg/gitg-lanes.vala
@@ -132,8 +132,6 @@ public class Lanes : Object
 	public void reset(Ggit.OId[]?           reserved = null,
 	                  Gee.HashSet<Ggit.OId>? roots    = null)
 	{
-		d_previous = new SList<weak Commit>();
-
 		d_lanes = new Gee.LinkedList<LaneContainer>();
 		d_roots = roots;
 
@@ -331,32 +329,36 @@ public class Lanes : Object
 		{
 			var commit = item.data;
 			unowned SList<Lane> lns = commit.get_lanes();
-			unowned Lane lane = lns.nth_data(index);
 
-			if (item.next != null)
+			if (lns != null)
 			{
-				var newindex = lane.from.data;
-
-				lns = commit.remove_lane(lane);
+				unowned Lane lane = lns.nth_data(index);
 
-				if (item.next.next != null)
+				if (item.next != null)
 				{
-					update_merge_indices(lns, newindex, -1);
-				}
+					var newindex = lane.from.data;
 
-				var mylane = commit.mylane;
+					lns = commit.remove_lane(lane);
 
-				if (mylane > index)
+					if (item.next.next != null)
+					{
+						update_merge_indices(lns, newindex, -1);
+					}
+
+					var mylane = commit.mylane;
+
+					if (mylane > index)
+					{
+						--commit.mylane;
+					}
+
+					index = newindex;
+				}
+				else
 				{
-					--commit.mylane;
+					lane.tag |= LaneTag.END;
+					lane.boundary_id = container.to;
 				}
-
-				index = newindex;
-			}
-			else
-			{
-				lane.tag |= LaneTag.END;
-				lane.boundary_id = container.to;
 			}
 
 			item = item.next;
