##
 * subject.pm
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
package subject;
use base qw(handler);
sub new {
my ($class,$value,$adjustfactor,$sharedmem)=@_;
$class->SUPER::new({value=>$value,adjustfactor=>$adjustfactor,sharedmem=>$sharedmem,announce=>0,observers=>[]});
}
sub register {
my ($ref,@observer)=@_;
push @{$ref->{observers}},@observer;
}
sub evaluate {
my $ref=shift;
my $maximum=$ref->{value};
foreach(split(':',$ref->{sharedmem}->getfromindex(2))) {
if($_ > $maximum) {
$maximum=$_;
}
}
$ref->{sharedmem}->setinindex(2,undef);
if($ref->{value}==$maximum) {
if($ref->{announce}==3) {
print "all three announcement over, final bidding at:",$ref->{value},"\n";
return "stop";
}else {
$ref->{announce}=$ref->{announce}+1;
print "making announcement number:",$ref->{announce},", at:",$ref->{value},"\n";
$ref->{sharedmem}->setinindex(1,$ref->{sharedmem}->getfromindex(1)+$ref->{adjustfactor});
}
}else {
$ref->{announce}=0;
$ref->{sharedmem}->setinindex(1,0);
$ref->{value}=$maximum;
print "auctioneer:new bidding rate:",$maximum,"\n";
}
map ($_->notify(), @{$ref->{observers}});
$ref->{sharedmem}->setinindex(0,$ref->{value});
#$ref->{sharedmem}->setinindex(1,$ref->{adjustfactor});
}
1;
