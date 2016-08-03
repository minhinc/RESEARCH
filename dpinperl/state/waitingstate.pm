##
 * waitingstate.pm
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
package waitingstate;
use base qw(state);
sub bttn {
my ($ref,$lift,$floor,$bttn)=@_;
$ref->SUPER::bttn($lift,$floor,$bttn);
if($lift->{BUTTON}[$lift->{FLOOR}] & 7) {
$lift->{BUTTON}[$lift->{FLOOR}]=0;
$lift->open;
}
}
sub close() {
my ($ref,$lift)=@_;
if($lift->bttnenable($lift->{FLOOR}+1,1,4)) {
$lift->state($ref->upstate);
}elsif($lift->bttnenable($lift->{FLOOR}-1,2,4)) {
$lift->state($ref->downstate);
}elsif($lift->bttnenable($lift->{FLOOR}+1,1,3)) {
$lift->state($ref->upstate);
}elsif($lift->bttnenable($lift->{FLOOR}-1,2,3)) {
$lift->state($ref->downstate);
}

if($lift->{PEOPLE}>=$lift->{MAXALLOWED}) {
if($lift->state==$ref->upstate) {
$lift->state($ref->fullupstate);
}else {
if($lift->state==$ref->downstate) {
$lift->state=$ref->fulldownstate;
}
}
}

if($lift->state != $ref->waitingstate) {
$lift->mvflr;
}
}
1;
