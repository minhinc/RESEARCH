##
 * state.pm
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
package state;
use upstate;
use downstate;
use fullupstate;
use fulldownstate;
use waitingstate;
my ($waitingstate,$upstate,$downstate,$fullupstate,$fulldownstate)=undef;
sub waitingstate {
$waitingstate='waitingstate'->new if !defined $waitingstate;
$waitingstate;
}
sub upstate {
$upstate='upstate'->new if !defined $upstate;;
$upstate;
}
sub downstate {
$downstate='downstate'->new if !defined $downstate;
$downstate;
}
sub fullupstate {
$fullupstate='fullupstate'->new if !defined $fullupstate;
$fullupstate;
}
sub fulldownstate {
$fulldownstate='fulldownstate'->new if !defined $fulldownstate;
$fulldownstate;
}
sub new {
my $class=shift;
bless {},$class;
}
sub bttn {
my ($ref,$lift,$targetfloor,$updowninside)=@_;
$lift->{BUTTON}[$targetfloor]|=$updowninside;
}
sub gtinout {
my ($ref,$lift,$inout,$user)=@_;
if($inout==2) {
$lift->{PEOPLE}=$lift->{PEOPLE}+1;
print "one person getting in, PEOPLE:",$lift->{PEOPLE},"\n";
}else {
$lift->{PEOPLE}=$lift->{PEOPLE}-1;
print "one person getting out, PEOPLE:",$lift->{PEOPLE},"\n";
$lift->scheduler->unregister($user);
}
}
sub bttnenable {
my ($ref,$lift,$floor,$updown,$bttn)=@_;
my $count=0;
if($floor<0 && $floor>$lift->{TOPFLOOR}) {
0;
}else {
if($updown==1) {
foreach($floor..$lift->{TOPFLOOR}) {
$count=$count+($lift->{BUTTON}[$_]&$bttn);
}
}else {
foreach(0..$floor) {
$count=$count+($lift->{BUTTON}[$_]&$bttn);
}
}
}
$count;
}
sub execute {
my ($ref,$lift)=@_;
if($lift->{openstate} && time>$lift->{closedrwaittime}) {
$lift->close;
}else {
if($lift->{liftmving} && time>$lift->{nextflrwaittime}) {
$lift->nextflr;
}
}
}
1;
