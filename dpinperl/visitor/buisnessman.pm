##
 * buisnessman.pm
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
package buisnessman;
use base qw(element);
sub new {
my ($class,$name,@buisnesstype)=@_;
$class->SUPER::new({name=>$name,buisnesstype=>\@buisnesstype});
}
sub enumerate {
my $ref=shift;
$ref->{buisnesstype};
}
sub accept {
my ($ref,$visitor)=@_;
$visitor->visit($ref);
}
sub name {
$_[0]->{name};
}
1;
