##
 * drawingapi1.pm
 # Design Patterns in Perl
 # Copyright (c) 2015-2016 Minh Inc www.minhinc.com
 #
 # This file is part of DesignPatternsInPerl
 #
 # DesignPatternsInPerl
 # modify it under the terms of the GNU Lesser General Public
 # License as published by the Free Software Foundation; either
 # version 2.1 of the License, or (at your option) any later version.
 #
 # DesignPatternsInPerl
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 # Lesser General Public License for more details.
 #
 # You should have received a copy of the GNU Lesser General Public
 # License along with Mgmp; if not, write to the Free Software
 # Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
##
package drawingapi1;
use base qw(drawingapi);
sub drawrectangle {
my ($ref, $x1, $y1, $x2, $y2)=@_;
printf "drawingapi1::drawrectangle, x1=%d, y1=%d, x2=%d, y2=%d\n",$x1,$y1,$x2,$y2;
}
sub drawcircle {
my ($ref, $x, $y, $radius)=@_;
printf "drawingapi1::drawcircle, x=>%d, y=>%d, radius=>%d\n",$x,$y,$radius;
}
1;
