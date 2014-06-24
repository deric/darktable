/*
    RawSpeed - RAW file decoder.

    Copyright (C) 2009-2014 Klaus Post
    Copyright (C) 2014 Pedro Côrte-Real

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

    http://www.klauspost.com
*/
#ifndef DCR_DECODER_H
#define DCR_DECODER_H

#include "RawDecoder.h"
#include "TiffIFDBE.h"

namespace RawSpeed {

class DcrDecoder :
  public RawDecoder
{
public:
  DcrDecoder(TiffIFD *rootIFD, FileMap* file);
  virtual ~DcrDecoder(void);
  virtual RawImage decodeRawInternal();
  virtual void checkSupportInternal(CameraMetaData *meta);
  virtual void decodeMetaDataInternal(CameraMetaData *meta);
protected:
  TiffIFD *mRootIFD;
  const uchar8 *in;
  void decodeKodak65000(ByteStream &input, uint32 w, uint32 h, const ushort16 *curve);
  void decodeKodak65000Segment(short *out, int bsize);
};

} // namespace RawSpeed

#endif
