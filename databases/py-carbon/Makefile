# Created by: Evan Sarmiento <bsdports@wayfair.com>
# $FreeBSD: head/databases/py-carbon/Makefile 386691 2015-05-18 17:07:45Z mat $

PORTNAME=	carbon
PORTVERSION=	0.9.15
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Backend storage application for graphite

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}txamqp>=0.3:${PORTSDIR}/net/py-txamqp \
		${PYTHON_PKGNAMEPREFIX}whisper>=0.9.10:${PORTSDIR}/databases/py-whisper \
		${PYTHON_PKGNAMEPREFIX}django>=1.4:${PORTSDIR}/www/py-django

USE_PYTHON=	distutils
USES=		python:2 twisted:run
USE_RC_SUBR=	carbon
USE_GITHUB=	yes
GH_ACCOUNT=	graphite-project

post-stage:
	${RM} -rf ${STAGEDIR}${PREFIX}/examples/init.d
	${RMDIR} ${STAGEDIR}${PREFIX}/examples

.include <bsd.port.mk>
