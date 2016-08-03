##
 * digitelement.pm
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
package digitelement;
use base qw(handler);
sub handle {
my ($ref,$tempref)=@_;
my $numberref=(ref $tempref?$tempref:\$tempref);
my ($startpos,$diffpos,$one,$two);
print "${$numberref}\n" if $ref->{POSITION} eq length($$numberref);
my $pos=$ref->{POSITION};
while($ref->{POSITION}<length($$numberref)&&$pos<=length($$numberref)){
$ref->next->handle($numberref);
do {
$startpos=$ref->{POSITION}-1;
$diffpos=++$pos-$ref->{POSITION};
$$numberref=~/.{$startpos}(.{$diffpos})(.)?/;
($one,$two)=($1,$2);
}while defined --$diffpos && $one=~/.+/ && $two=~/.+/ && $one=~/$two/;
$$numberref=~s/(.{$startpos})(.)(.{$diffpos})(.)/\1\4\3\2/ if $pos<=length($$numberref);
}
$pos=$ref->{POSITION};
while($pos<length($$numberref)) {
$startpos=$pos++-1;
$$numberref=~s/(.{$startpos})(.)(.)/\1\3\2/;
}
}
1;
