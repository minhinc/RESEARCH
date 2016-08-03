##
 * person.pm
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
package person;
use base qw(handler);
sub new {
my ($class,$scheduler,$lift)=@_;
$class->SUPER::new({users=>[],scheduler=>$scheduler,lift=>$lift,begintime=>time});
}
sub adduser {
my ($ref,@users)=@_;
push @{$ref->{users}},@users;
}
sub execute {
my $ref=shift;
if(! scalar @{$ref->{users}}) {
$ref->{scheduler}->unregister($ref);
} else {
my $i=0;
while(1) {
last if $i >= scalar @{$ref->{users}};
if($ref->{users}[$i]{entertime}<(time-$ref->{begintime})) {
$ref->{scheduler}->register($ref->{users}[$i]);
splice(@{$ref->{users}},$i,1);
}else {
$i=$i+1;
}
}
}
}
sub getlift {
my $ref=shift;
$ref->{lift};
}
1;
