# Created by: nork@FreeBSD.org
# $FreeBSD: head/databases/linux-oracle-instantclient-sqlplus/Makefile 362584 2014-07-22 21:15:34Z rene $

PORTNAME=		instantclient
PORTVERSION=		${ORACLEVERSION}
PORTREVISION=		3
CATEGORIES=		databases
MASTER_SITES=		#http://www.oracle.com/technology/software/tech/oci/instantclient/
PKGNAMEPREFIX=		linux-oracle-
PKGNAMESUFFIX=		-sqlplus
DISTNAME=		${PORTNAME}${PKGNAMESUFFIX}-${LINUXARCH}-${ORACLEVERSION}
DIST_SUBDIR=		oracle

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Oracle 12c Linux InstantClient SQLPlus for RDBMS 8.1.2+

ONLY_FOR_ARCHS=		i386 amd64
NO_BUILD=		yes

RESTRICTED=		Packaging prohibited by Oracle license

USES=			zip
USE_LINUX=		yes
USE_LINUX_PREFIX=	yes

ORACLEVERSION=		12.1.0.2.0

BINS_LIST=		sqlplus

LIBS_LIST=		glogin.sql	\
			libsqlplus.so	\
			libsqlplusic.so

WRKSRC=			${WRKDIR}/instantclient_12_1

INSTBINSDIR=		${STAGEDIR}${PREFIX}/usr/bin
INSTLIBSDIR=		${STAGEDIR}${PREFIX}/usr/lib/oracle/${ORACLEVERSION}/client/lib

USE_LDCONFIG=		${PREFIX}/usr/lib/oracle/${ORACLEVERSION}/client/lib

PLIST_SUB=		ORACLEVERSION=${ORACLEVERSION}

.include <bsd.port.pre.mk>

LINUXARCH=		linux

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE+=	due to Oracle license restrictions, you must fetch the source distribution manually from http://www.oracle.com/technetwork/database/features/instant-client/index-097480.html , follow the link for ${DISTFILES} and place them in ${DISTDIR}/${DIST_SUBDIR}/
.endif

do-install:
	@${MKDIR} -m 0755 ${INSTBINSDIR}
	@${MKDIR} -m 0755 ${INSTLIBSDIR}
.for i in ${BINS_LIST}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${INSTBINSDIR}/${i}
.endfor
.for i in ${LIBS_LIST}
	${INSTALL_DATA} ${WRKSRC}/${i} ${INSTLIBSDIR}/${i}
.endfor

.include <bsd.port.post.mk>
