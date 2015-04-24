# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD: head/textproc/kibana/Makefile 374010 2014-12-05 12:28:51Z antoine $

PORTNAME=	kibana
PORTVERSION=	3.1.2
CATEGORIES=	textproc www
MASTER_SITES=	http://download.elasticsearch.org/kibana/kibana/

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Browser based analytics and search interface to ElasticSearch

LICENSE=	APACHE20

NO_BUILD=	yes
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	${MV} ${STAGEDIR}${WWWDIR}/config.js ${STAGEDIR}${WWWDIR}/config.js.sample

.include <bsd.port.mk>
