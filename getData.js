/*var freqData=[
	{Country:'USA',freq:{USA:4786, Russia:1319, China:249, India:100}}
	,{Country:'China',freq:{USA:1101, Russia:412, China:674, India:100}}
	,{Country:'Russia',freq:{USA:932, Russia:2149, China:418, India:100}}
	,{Country:'Canada',freq:{USA:832, Russia:1152, China:1862, India:100}}
	,{Country:'France',freq:{USA:4481, Russia:3304, China:948, India:100}}
	,{Country:'Germany',freq:{USA:1619, Russia:167, China:1063, India:100}}
	,{Country:'Mexico',freq:{USA:1819, Russia:247, China:1203, India:100}}
	,{Country:'Spain',freq:{USA:4498, Russia:3852, China:942, India:100}}
	,{Country:'India',freq:{USA:797, Russia:1849, China:1534, India:100}}
	,{Country:'Japan',freq:{USA:162, Russia:379, China:471, India:100}}
	];

	dashboard('#dashboard',freqData);
*/

//get data from dropdown selection
var country1, country2;
$(document).ready(function() {
      $('#submitButton').click(function(event) {
		country1 = $('#sel1 option:selected').val();
		country2 = $('#sel2 option:selected').val();
		console.log(country1);
		console.log(country2);
		$.getJSON("http://rhubarb-cake-89591.herokuapp.com/fantasy/api/v1.0/predictions", function( data) {
			var items = [];
			$.each( data, function( key, val ) {
				items.push(val);
			});
     
      var data = [];
      for (i=0; i< items[0].length; i++){
        data.push(items[0][i]);
      }
      var countries =[];
      for (i=0; i<data.length; i++){
        var countryData = data[i]["country"]["name"];
        var freq = {};
        for (x in data[i]["votes"]){
          freq[x] = data[i]["votes"][x];
          console.log(freq[x]);
          if ((countryData == country1)&&(x == country2))
            freq[x] = freq[x] + 50; 
          console.log(freq[x]);
        }
        var element = {};
        element.Country = countryData;
        element.freq = freq;
        countries.push(element);
      }
      dashboard('#dashboard', countries);
    });
   });
});



