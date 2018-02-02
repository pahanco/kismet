/*
    This file is part of Kismet

    Kismet is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Kismet is distributed in the hope that it will be useful,
      but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Kismet; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "dot11_ie_221_vendor.h"

void dot11_ie_221_vendor::parse(std::shared_ptr<kaitai::kstream> p_io) {
    m_vendor_oui = p_io->read_bytes(3);
    m_vendor_tag = p_io->read_bytes_full();
    m_vendor_tag_stream.reset(new kaitai::kstream(m_vendor_tag));
    // Get the type (maybe type, depending) from a literal position then
    // rewind the io stream to just after the vendor oui
    m_vendor_oui_type = p_io->read_u1();
    p_io->seek(3);
}

