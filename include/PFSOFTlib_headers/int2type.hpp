//
//  int2type.hpp
//  PFSOFTlib
//
//   Created by Denis-Michael Lux on 09. June 2018.
//
//   This file is part of PFSOFTlib.
//
//   PFSOFTlib is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
//   PFSOFTlib is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with PFSOFTlib.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef PFSOFTlib_int2type_hpp
#define PFSOFTlib_int2type_hpp

PFSOFT_BEGIN

template <int v>
struct Int2Type
{
    enum { value = v };
};

PFSOFT_END

#endif
