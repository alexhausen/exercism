#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H

namespace space_age {

class space_age{
public:
    space_age(long secs): secs_{secs} {}
    float on_mercury() const {
        return secs_ / (earth_year_in_secs * 0.2408467);
    }

    float on_venus() const {
        return secs_ / (earth_year_in_secs * 0.61519726);
    }
    
    float on_earth() const {
        return secs_ / earth_year_in_secs;
    }
    
    float on_mars() const {
        return secs_ / (earth_year_in_secs * 1.8808158);
    }
    
    float on_jupiter() const {
        return secs_ / (earth_year_in_secs * 11.862615);
    }
    
    float on_saturn() const {
        return secs_ / (earth_year_in_secs * 29.447498);
    }
    
    float on_uranus() const {
        return secs_ / (earth_year_in_secs * 84.016846);
    }

    float on_neptune() const {
        return secs_ / (earth_year_in_secs * 164.79132);
    }

    long seconds() const { return secs_; }

private:
    long secs_;

    static constexpr float earth_year_in_secs = 31557600.0f;
};
}  // namespace space_age

#endif // SPACE_AGE_H