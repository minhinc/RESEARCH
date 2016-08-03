##
 * adder.pm
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
package adder;
use base qw(expression);
sub interpret {
my ($ref,$context)=@_;
print "adder::context:",$$context,"\n";
my ($muldivcontext,$result,$subtractcontext);
while($$context=~/(.+?)(?<![\/*])(\+|-)(.*)/) {
$muldivcontext=$1;
$$context="$2$3";
if(scalar (grep {/-/} split('',$muldivcontext))%2) {
$subtractcontext="$subtractcontext$muldivcontext";
next;
}
$ref->{EXPRESSION1}->interpret(\$muldivcontext) && $ref->{EXPRESSION2}->interpret(\$muldivcontext);
$result+=$muldivcontext;
}
$ref->{EXPRESSION1}->interpret($context) && $ref->{EXPRESSION2}->interpret($context) if !scalar (grep {/-/} split('',$$context))%2;
if($$context!~/^-/) {
$result+=$$context;
}else {
$subtractcontext="$subtractcontext$$context";
}
if($subtractcontext=~/^-/) {
$result="$result$subtractcontext";
}else {
$result="$result+$subtractcontext";
}
$$context=$result;
}
1;
