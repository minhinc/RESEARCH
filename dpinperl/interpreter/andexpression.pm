##
 * andexpression.pm
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
package andexpression;
use base qw(expression);
sub new {
my ($class,$expression1,$expression2)=@_;
my $ref=$class->SUPER::new({EXPRESSION1=>$expression1,EXPRESSION2=>$expression2});
$ref;
}
sub interpret {
my ($ref,$context)=@_;
$ref->{EXPRESSION1}->interpret($context) && $ref->{EXPRESSION2}->interpret($context);
}
1;
