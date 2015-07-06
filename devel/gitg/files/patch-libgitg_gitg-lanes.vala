--- libgitg/gitg-lanes.vala.orig	2015-07-06 13:42:13 UTC
+++ libgitg/gitg-lanes.vala
@@ -332,31 +332,33 @@ public class Lanes : Object
 			var commit = item.data;
 			unowned SList<Lane> lns = commit.get_lanes();
 			unowned Lane lane = lns.nth_data(index);
+			
+			if(lns!=null && lane != null){
+				if (item.next != null)
+				{
+					var newindex = lane.from.data;
 
-			if (item.next != null)
-			{
-				var newindex = lane.from.data;
+					lns = commit.remove_lane(lane);
 
-				lns = commit.remove_lane(lane);
+					if (item.next.next != null)
+					{
+						update_merge_indices(lns, newindex, -1);
+					}
 
-				if (item.next.next != null)
-				{
-					update_merge_indices(lns, newindex, -1);
-				}
+					var mylane = commit.mylane;
 
-				var mylane = commit.mylane;
+					if (mylane > index)
+					{
+						--commit.mylane;
+					}
 
-				if (mylane > index)
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
