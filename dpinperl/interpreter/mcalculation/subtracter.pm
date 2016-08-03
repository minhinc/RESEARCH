##
 * subtracter.pm
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
package subtracter;
use base qw(expression);
sub interpret {
my ($ref,$context)=@_;
print "subtracter::context:",$$context,"\n";
my $muldivcontext;
my $result=undef;
while($$context=~/(.+?)(?<![\/*])(\+|-)(.*)/) {
$muldivcontext=$1;
$$context="$2$3";
$ref->{EXPRESSION1}->interpret(\$muldivcontext) && $ref->{EXPRESSION2}->interpret(\$muldivcontext);
if(!defined $result) {
$result=$muldivcontext;
}else {
$muldivcontext=~s/-//;
$result-=$muldivcontext;
}
}
$ref->{EXPRESSION1}->interpret($context) && $ref->{EXPRESSION2}->interpret($context);
if($$context=~/^-(.*)/) {
$result-=$1;
}else {
$result=$1;
}
$$context=$result;
}
1;
