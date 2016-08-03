##
 * fullupstate.pm
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
package fullupstate;
use base qw(state);
sub nextflr {
my ($ref,$lift)=@_;
$lift->{FLOOR}=$lift->{FLOOR}+1;
print "fullupstate:next floor:",$lift->{FLOOR},"\n";
if($lift->{BUTTON}[$lift->{FLOOR}]&4) {
$lift->{BUTTON}[$lift->{FLOOR}]&3;
$lift->open;
}else {
$ref->close($lift);
}
}
sub close {
my ($ref,$lift)=@_;
if($lift->{PEOPLE}<=$lift->{MAXCOUNT}) {
$lift->state($ref->upstate);
$lift->state->close($lift);
}else {
if(!$lift->bttnenable($lift->{FLOOR}+1,1,4)) {
if($lift->bttnenable($lift->{FLOOR}-1,2,4)) {
$lift->state($ref->fulldownstate);
}else {
$lift->state($ref->waitingstate);
}
}
if($lift->state!=$ref->waitingstate) {
$lift->mvflr;
}
}
}
1;
