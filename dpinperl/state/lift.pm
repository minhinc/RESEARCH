##
 * lift.pm
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
package lift;
use base qw(handler);
sub new {
my ($class,$scheduler,$state)=@_;
$class->SUPER::new({BUTTON=>[],FLOOR=>0,openstate=>0,liftmving=>0,PEOPLE=>0,MAXALLOWED=>5,TOPFLOOR=>5,nextflrwaittime=>0,closedrwaittime=>0,scheduler=>$scheduler,STATE=>$state});
}
sub open {
my $ref=shift;
print "door opened at floor:",$ref->{FLOOR},"\n";
$ref->{closedrwaittime}=time+1;
$ref->{openstate}=1;
}
sub isopen() {
my $ref=shift;
if($ref->{openstate}) {
$ref->{FLOOR};
}else {
$ref->{TOPFLOOR}+1;
}
}
sub close {
my $ref=shift;
print "door closed at floor:",$ref->{FLOOR},"\n";
$ref->{openstate}=0;
$ref->{STATE}->close($ref);
}
sub mvflr {
my $ref=shift;
$ref->{nextflrwaittime}=time+2;
$ref->{liftmving}=1;
}
sub nextflr {
my $ref=shift;
$ref->{liftmving}=0;
$ref->{STATE}->nextflr($ref);
}
sub state {
my $ref=shift;
if(scalar @_) {
print "old state:",$ref->{STATE};
$ref->{STATE}=shift;
print ": changed to ",$ref->{STATE},"\n";
}else {
$ref->{STATE};
}
}
sub scheduler {
$_[0]->{scheduler};
}
sub execute {
my $ref=shift;
$ref->{STATE}->execute($ref);
}
1;
