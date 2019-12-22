function meow = echoe(input,delay,loudness)
new_input = [];
for n = 1:length(input)/10:length(input)
    new_input = [new_input;input(n:n+delay)]*loudness;
end
meow = new_input;
sound(meow)
return;