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

use scheduler;
use person;
use user;
use liftevent;
use waitingstate;
$|=1;
my $scheduler=new scheduler;
my $lift=new liftevent($scheduler,'waitingstate'->waitingstate);
my $person=new person($scheduler,$lift);
$person->adduser(new user($person,0,0,1),new user($person,0,5,0),new user($person,0,1,5),new user($person,10,0,3),new user($person,4,5,2),new user($person,5,2,3),new user($person,5,4,1),new user($person,3,0,2),new user($person,14,3,0),new user($person,2,3,4),new user($person,0,2,5),new user($person,0,4,0),new user($person,0,3,1),new user($person,0,0,1));
#$person->adduser(new user($person,0,5,0),new user($person,0,1,5),new user($person,0,2,5),new user($person,0,4,0),new user($person,0,3,1));
$scheduler->register($person,$lift);
$scheduler->start;
