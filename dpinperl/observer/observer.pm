##
 * observer.pm
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
package observer;
use base qw(handler);
sub new {
my ($class,$bidvalue,$sharedmem)=@_;
$class->SUPER::new({bidvalue=>$bidvalue,sharedmem=>$sharedmem});
}
sub notify {
my $ref=shift;
$ref->{notified}=1;
}
sub bid {
my $ref=shift;
print "bidder:bidding at:",$ref->{bidvalue},"\n";
$ref->{sharedmem}->setinindex(2,join(':',$ref->{sharedmem}->getfromindex(2),$ref->{bidvalue}));
}
sub evaluate {
my $ref=shift;
if($ref->{notified}) {
$ref->{notified}=0;
if($ref->{bidvalue}>$ref->{sharedmem}->getfromindex(0) && $ref->{bidvalue}<($ref->{sharedmem}->getfromindex(0)+$ref->{sharedmem}->getfromindex(0)*$ref->{sharedmem}->getfromindex(1)/100)) {
$ref->bid;
}
}
}
1;
