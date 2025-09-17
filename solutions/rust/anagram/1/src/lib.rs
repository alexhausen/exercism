use std::collections::HashSet;

fn is_anagram<'a>(word: &str, possible_anagram: &str) -> bool {

    let w = word.to_lowercase();
    let w = w.as_str();
    let pa = possible_anagram.to_lowercase();
    let pa = pa.as_str();
    let mut w_letters_used = vec![false; w.chars().count()];
    let mut pa_letters_used = vec![false; pa.chars().count()];

    if w == pa {
        return false;
    }

    let mut i = 0;
    for c1 in w.chars( ) {
        let mut found = false;
        let mut j = 0;
        for c2 in pa.chars() {
            if c1 == c2  && !w_letters_used[i] && !pa_letters_used[j] {
                w_letters_used[i] = true;
                pa_letters_used[j] = true;
                found = true;
                break;
            }
            j += 1;
        }
        if !found {
            return false;
        }
        i += 1;
    }
    w_letters_used.iter().all(|b| *b) && pa_letters_used.iter().all(|b| *b)
}

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &[&'a str]) -> HashSet<&'a str> {
    let mut hs: HashSet<&'a str> = Default::default();
    for possible_anagram in possible_anagrams.iter() {
        if is_anagram(word, possible_anagram) {
            hs.insert(possible_anagram);
        }
    }
    hs
}
