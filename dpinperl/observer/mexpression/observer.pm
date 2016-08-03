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
use sharedmem;
use base qw(handler);
sub evaluate {
my $ref=shift;
my $expression;
if($ref->{notified}) {
$expression='sharedmem'->instance->getfromindex(0);
while ($expression=~/(-?\d+)($ref->{operator})(-?\d+)/) {
$expression=join('',$`,eval "$1$2$3",$');
}
'sharedmem'->instance->setinindex(2,$expression);
'sharedmem'->instance->setinindex(1,0);
$ref->{notified}=false;
}
}
sub notify {
my $ref=shift;
$ref->{notified}=true;
}
sub getexpression {
'sharedmem'->instance->getfromindex(0);
}
1;
