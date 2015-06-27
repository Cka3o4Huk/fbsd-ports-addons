--- input-v4l.c.orig	2005-01-27 02:08:39 UTC
+++ input-v4l.c
@@ -34,6 +34,7 @@
 #ifdef HAVE_LINUX_COMPILER_H
 #include <linux/compiler.h>
 #endif
+#include <libv4l1.h>
 #include <linux/videodev.h>
 #ifdef HAVE_PWC_IOCTL_H
 #include <pwc-ioctl.h>
@@ -108,7 +109,7 @@ static void *capture_loop( void *d )
 	mm.height = conf->height;
 	mm.format = VIDEO_PALETTE_YUV420P;
 
-	if( ioctl( conf->fd, VIDIOCMCAPTURE, &mm ) < 0 )
+	if( v4l1_ioctl( conf->fd, VIDIOCMCAPTURE, &mm ) < 0 )
 	{
 		spook_log( SL_ERR, "v4l: aborting on error in VIDIOCMCAPTURE: %s",
 				strerror( errno ) );
@@ -124,7 +125,7 @@ static void *capture_loop( void *d )
 		mm.height = conf->height;
 		mm.format = VIDEO_PALETTE_YUV420P;
 
-		if( ioctl( conf->fd, VIDIOCMCAPTURE, &mm ) < 0 )
+		if( v4l1_ioctl( conf->fd, VIDIOCMCAPTURE, &mm ) < 0 )
 		{
 			spook_log( SL_ERR,
 				"v4l: aborting on error in VIDIOCMCAPTURE: %s",
@@ -134,7 +135,7 @@ static void *capture_loop( void *d )
 
 		cur_buf = cur_buf ^ 1;
 
-		if( ioctl( conf->fd, VIDIOCSYNC, &cur_buf ) < 0 )
+		if( v4l1_ioctl( conf->fd, VIDIOCSYNC, &cur_buf ) < 0 )
 		{
 			spook_log( SL_ERR,
 				"v4l: aborting on error in VIDIOCSYNC: %s",
@@ -200,7 +201,7 @@ static void *capture_loop( void *d )
 		f->height = conf->height;
 		f->key = 1;
 		frames = 0;
-
+		
 		copy_yuv420p_to_uyvy( f->d,
 				conf->mmap_buf + conf->vm.offsets[cur_buf],
 				f->width, f->height );
@@ -234,13 +235,14 @@ static int v4l_setup( struct v4l_input *
 
 	conf->cur_frame = -1;
 
-	if( ( conf->fd = open( conf->device, O_RDWR ) ) < 0 )
+	if( ( conf->fd = v4l1_open( conf->device, O_RDWR ) ) < 0 )
 	{
 		spook_log( SL_ERR, "v4l: unable to open %s: %s",
 				conf->device, strerror( errno ) );
 		return -1;
 	}
-	if( ioctl( conf->fd, VIDIOCGCAP, &vc ) < 0 )
+	
+	if( v4l1_ioctl( conf->fd, VIDIOCGCAP, &vc ) < 0 )
 	{
 		spook_log( SL_ERR, "v4l: error determining device capabilities" );
 		return -1;
@@ -262,7 +264,7 @@ static int v4l_setup( struct v4l_input *
 #ifdef HAVE_PWC_IOCTL_H
 	/* This is apparently how we're supposed to probe for PWC devices... */
 	if( sscanf( vc.name, "Philips %d webcam", &i ) == 1 ||
-		( ioctl( conf->fd, VIDIOCPWCPROBE, &pwc_probe ) == 0 &&
+		( v4l1_ioctl( conf->fd, VIDIOCPWCPROBE, &pwc_probe ) == 0 &&
 			! strcmp( vc.name, pwc_probe.name ) ) )
 	{
 		spook_log( SL_INFO, "v4l: activating support for Philips webcams" );
@@ -279,7 +281,7 @@ static int v4l_setup( struct v4l_input *
 		for( i = 0; i < vc.channels; ++i )
 		{
 			chan.channel = i;
-			if( ioctl( conf->fd, VIDIOCGCHAN, &chan ) < 0 )
+			if( v4l1_ioctl( conf->fd, VIDIOCGCHAN, &chan ) < 0 )
 			{
 				spook_log( SL_ERR,
 					"v4l: error getting info on input port" );
@@ -304,13 +306,13 @@ static int v4l_setup( struct v4l_input *
 		chan.norm = VIDEO_MODE_AUTO;
 		break;
 	}
-	if( ioctl( conf->fd, VIDIOCSCHAN, &chan ) < 0 )
+	if( v4l1_ioctl( conf->fd, VIDIOCSCHAN, &chan ) < 0 )
 	{
 		spook_log( SL_ERR, "v4l: error selecting input port" );
 		return -1;
 	}
 
-	if( ioctl( conf->fd, VIDIOCGPICT, &pict ) < 0 )
+	if( v4l1_ioctl( conf->fd, VIDIOCGPICT, &pict ) < 0 )
 	{
 		spook_log( SL_ERR, "v4l: error querying palette parameters" );
 		return -1;
@@ -319,7 +321,7 @@ static int v4l_setup( struct v4l_input *
 	pict.palette = VIDEO_PALETTE_YUV420P;
 	pict.depth = 24;
 
-	if( ioctl( conf->fd, VIDIOCSPICT, &pict ) < 0 )
+	if( v4l1_ioctl( conf->fd, VIDIOCSPICT, &pict ) < 0 )
 	{
 		spook_log( SL_ERR, "v4l: error setting palette parameters" );
 		return -1;
@@ -344,7 +346,7 @@ static int v4l_setup( struct v4l_input *
 		}
 	}
 	
-	if( ioctl( conf->fd, VIDIOCSWIN, &win ) < 0 )
+	if( v4l1_ioctl( conf->fd, VIDIOCSWIN, &win ) < 0 )
 	{
 		if( conf->inputtype == INPUTTYPE_WEBCAM && conf->fps > 0 )
 			spook_log( SL_ERR,
@@ -357,7 +359,7 @@ static int v4l_setup( struct v4l_input *
 
 	memset( &win, 0, sizeof( win ) );
 
-	if( ioctl( conf->fd, VIDIOCGWIN, &win ) < 0 )
+	if( v4l1_ioctl( conf->fd, VIDIOCGWIN, &win ) < 0 )
 	{
 		spook_log( SL_ERR, "v4l: error verifying image parameters" );
 		return -1;
@@ -386,7 +388,7 @@ static int v4l_setup( struct v4l_input *
 #endif
 
 #ifdef VIDIOCPWCGREALSIZE
-	if( pwc && ioctl( conf->fd, VIDIOCPWCGREALSIZE, &pwc_imagesize ) == 0 )
+	if( pwc && v4l1_ioctl( conf->fd, VIDIOCPWCGREALSIZE, &pwc_imagesize ) == 0 )
 	{
 		real_width = pwc_imagesize.width;
 		real_height = pwc_imagesize.height;
@@ -412,7 +414,7 @@ static int v4l_setup( struct v4l_input *
 		win.clips = NULL;
 		win.clipcount = 0;
 		
-		if( ioctl( conf->fd, VIDIOCSWIN, &win ) < 0 )
+		if( v4l1_ioctl( conf->fd, VIDIOCSWIN, &win ) < 0 )
 		{
 			spook_log( SL_ERR,
 				"v4l: error setting image parameters" );
@@ -424,7 +426,7 @@ static int v4l_setup( struct v4l_input *
 
 #ifdef HAVE_PWC_IOCTL_H
 	if( pwc &&
-		ioctl( conf->fd, VIDIOCPWCSAWB, &conf->pwc_whitebalance ) < 0 )
+		v4l1_ioctl( conf->fd, VIDIOCPWCSAWB, &conf->pwc_whitebalance ) < 0 )
 	{
 		spook_log( SL_ERR,
 			"v4l: error setting white balance on Philips webcam" );
@@ -432,13 +434,13 @@ static int v4l_setup( struct v4l_input *
 	}
 #endif
 
-	if( ioctl( conf->fd, VIDIOCGMBUF, &conf->vm ) < 0 )
+	if( v4l1_ioctl( conf->fd, VIDIOCGMBUF, &conf->vm ) < 0 )
 	{
 		spook_log( SL_ERR, "v4l: error configuring driver for DMA" );
 		return -1;
 	}
 
-	if( ! ( conf->mmap_buf = (unsigned char *)mmap( NULL, conf->vm.size, PROT_READ, MAP_SHARED, conf->fd, 0 ) ) )
+	if( ! ( conf->mmap_buf = (unsigned char *)v4l1_mmap( NULL, conf->vm.size, PROT_READ, MAP_SHARED, conf->fd, 0 ) ) )
 	{
 		spook_log( SL_ERR, "v4l: error mapping driver memory" );
 		return -1;
@@ -542,7 +544,11 @@ static int end_block( void *d )
 		{
 			conf->fincr = 1;
 			conf->fbase = conf->fps;
-		} else spook_log( SL_INFO, "v4l: must figure out framerate, this will take some time..." );
+		} else {
+			spook_log( SL_INFO, "v4l: must figure out framerate, this will take some time..." );
+			conf->fincr = 0; //fixing Valgrid errors
+		}
+		
 		if( conf->inputport < 0 ) conf->inputport = 0;
 		if( conf->width == 0 )
 		{
