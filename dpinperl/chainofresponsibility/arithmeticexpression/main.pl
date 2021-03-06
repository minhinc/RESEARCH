##
 * main.pl
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
use strict;
use warnings;
use divider;
use multiplier;
use subtracter;
use adder;

(my $handlerref=new divider(q(/)))->next(new multiplier(q(*)))->next(new subtracter(q(-)))->next(new adder(q(+)))->next(undef);
print "result:",$handlerref->handle(q(1+3/3*2-2+6/2/3-2)),"\n";
print "result:",$handlerref->handle(q(1-2+4*3-6/2+8*3-2*70/10));
