/*
 *  Copyright (c) 2008 Cyrille Berger <cberger@cberger.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
*/

#ifndef _KO_COLOR_CONVERSION_TRANSFORMATION_ABSTRACT_FACTORY_H_
#define _KO_COLOR_CONVERSION_TRANSFORMATION_ABSTRACT_FACTORY_H_

#include "kritapigment_export.h"

#include <KoColorConversionTransformation.h>
#include <KoColorProofingConversionTransformation.h>

class KRITAPIGMENT_EXPORT KoColorConversionTransformationAbstractFactory
{
public:
    KoColorConversionTransformationAbstractFactory() {}
    virtual ~KoColorConversionTransformationAbstractFactory() {}

    /**
     * Creates a color transformation between the source color space and the destination
     * color space.
     *
     * @param srcColorSpace source color space
     * @param dstColorSpace destination color space
     */
    virtual KoColorConversionTransformation* createColorTransformation(const KoColorSpace* srcColorSpace,
                                                                       const KoColorSpace* dstColorSpace,
                                                                       KoColorConversionTransformation::Intent renderingIntent,
                                                                       KoColorConversionTransformation::ConversionFlags conversionFlags) const = 0;

    virtual KoColorProofingConversionTransformation* createColorProofingTransformation(const KoColorSpace* srcColorSpace,
                                                                       const KoColorSpace* dstColorSpace,
                                                                       const KoColorSpace* proofingSpace,
                                                                       KoColorProofingConversionTransformation::Intent renderingIntent,
                                                                       KoColorProofingConversionTransformation::Intent proofingIntent,
                                                                       KoColorProofingConversionTransformation::ConversionFlags conversionFlags,
                                                                       quint8 *gamutWarning) const
    {
        Q_UNUSED(srcColorSpace);
        Q_UNUSED(dstColorSpace);
        Q_UNUSED(proofingSpace);
        Q_UNUSED(renderingIntent);
        Q_UNUSED(proofingIntent);
        Q_UNUSED(conversionFlags);
        Q_UNUSED(gamutWarning);
        qFatal("createColorProofinTransform undefined.");
        return 0;
    }
};

#endif
